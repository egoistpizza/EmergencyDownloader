# Emergency Downloader

A command-line utility to download trusted malware removal tools directly from **their official servers**.

## 🔗 Download

You can download the latest executable here:

➡️ [EmergencyDownloader.exe](https://github.com/egoistpizza/EmergencyDownloader/releases/latest/download/EmergencyDownloader.exe)


## Downloads

This tool fetches the following executables:

- RKill
- Emsisoft Emergency Kit
- HitmanPro
- Kaspersky Virus Removal Tool
- ESET Online Scanner

All files are saved in the `DownloadedFiles` directory with their original names.

## License

This project is licensed under the GNU General Public License v3.
See the LICENSE file for more details.

## Issues & Support

If you encounter any bugs or have feature requests, please open an issue here:

➡️ [https://github.com/egoistpizza/EmergencyDownloader/issues](https://github.com/egoistpizza/EmergencyDownloader/issues).

## Credits

Application icon by [flaticon.com](https://www.flaticon.com/free-icon/download_526804?term=security%20download&page=2&position=22&origin=search&related_id=526804), used with attribution.

## Build Instructions

```bash
git clone https://github.com/egoistpizza/EmergencyDownloader.git
cd EmergencyDownloader
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
```

---

© 2025 egoistpizza.
