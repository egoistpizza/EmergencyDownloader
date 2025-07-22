#include "Downloader.h"
#include <windows.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

Downloader::Downloader(const std::string& targetFolder) : targetFolder(targetFolder) {}

bool Downloader::downloadFile(const std::string& url, const std::string& filename) {
    std::string fullPath = targetFolder + "\\" + filename;

    HRESULT hr = URLDownloadToFileA(NULL, url.c_str(), fullPath.c_str(), 0, NULL);
    return (hr == S_OK);
}

std::string Downloader::getFilenameFromUrl(const std::string& url) {
    size_t pos = url.find_last_of("/\\");
    if (pos == std::string::npos)
        return url;
    return url.substr(pos + 1);
}

void Downloader::downloadAll(const std::vector<std::string>& urls,
                             std::function<void(const std::string&)> logCallback,
                             std::function<void(int)> progressCallback) {
    size_t total = urls.size();
    for (size_t i = 0; i < total; ++i) {
        const std::string& url = urls[i];
        std::string filename = getFilenameFromUrl(url);

        logCallback(filename + " is downloading...");
        bool ok = downloadFile(url, filename);
        if (ok) {
            logCallback(filename + " was downloaded successfully.");
        } else {
            logCallback("Failed to download " + filename + ".");
        }

        int progressPercent = static_cast<int>(((i + 1) * 100) / total);
        progressCallback(progressPercent);
    }
}
