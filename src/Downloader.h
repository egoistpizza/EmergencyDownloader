#pragma once

#include <string>
#include <vector>
#include <functional>

class Downloader {
public:
    Downloader(const std::string& targetFolder);

    void downloadAll(const std::vector<std::string>& urls,
                     std::function<void(const std::string&)> logCallback,
                     std::function<void(int)> progressCallback);

private:
    std::string targetFolder;

    bool downloadFile(const std::string& url, const std::string& filename);
    std::string getFilenameFromUrl(const std::string& url);
};
