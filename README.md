# cdecrypt_termux

A Wii U NUS content file decrypter optimized for Android (Termux).

## Installation
Run this one-line command to install `cdecrypt` to your system:

```bash
pkg update && pkg upgrade -y && pkg install -y git clang make && git clone https://github.com/manlemon223-prog/cdecrypt_termux.git && cd cdecrypt_termux && make && cp cdecrypt $PREFIX/bin/ && cd .. && rm -rf cdecrypt_termux
```

## Usage

### Basic Usage
Pass the path to a game directory (containing TMD and Ticket files):
```bash
cdecrypt "/path/to/game_folder"
```

### Manual Title Key
If a `title.tik` file is missing, provide the 32-character Title Key directly:
```bash
cdecrypt "/path/to/game_folder" 1500E19891AF46763AB79D95C341D48B
```

## Notes
- **Key Search:** Place a `keys.txt` in `/sdcard/Download/` for automatic Title Key discovery.
- **Auto-Cleanup:** Encrypted source files are automatically removed after successful decryption to save storage.
- **Shell Safety:** Always use **"quotes"** for paths containing spaces or parentheses.

## Credits
- Originally by **crediar**
- Maintained by **VitaSmith**
- Termux optimization by **manlemon223-prog**
