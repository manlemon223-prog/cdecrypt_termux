# cdecrypt_termux

A Wii U NUS content file decrypter optimized for Android (Termux).

## Installation
Run this one-line command to install `cdecrypt` to your system:

```bash
pkg update && pkg upgrade -y && pkg install -y git clang make && git clone https://github.com/manlemon223-prog/cdecrypt_termux.git && cd cdecrypt_termux && make && cp cdecrypt $PREFIX/bin/ && cd .. && rm -rf cdecrypt_termux
```

## Usage

### Basic Usage
If your game folder is in `/sdcard/Download/`, just type its name:
```bash
cdecrypt "Game Folder Name"
```
*Note: Use **"quotes"** if the name has spaces or parentheses.*

## Notes
- **Auto-Keygen:** If a `title.tik` is missing, `cdecrypt` will automatically generate one using the WiiUDownloader algorithm (mypass method).
- **Auto-Cleanup:** Encrypted source files are removed after successful decryption.

## Credits
- Originally by **crediar**
- Maintained by **VitaSmith**
- Termux optimization by **manlemon223-prog**
