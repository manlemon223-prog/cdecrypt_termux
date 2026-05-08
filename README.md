# cdecrypt (Patched for Termux/Android)

A Wii U NUS content file decrypter. This is a patched version of the VitaSmith cdecrypt, optimized for mobile use and incomplete game folders.

## Features
- **Auto-Discovery:** Automatically finds TMD and Ticket files even if they have non-standard names (e.g., `tmd.17` or `cetk`).
- **Manual Key Support:** Decrypt games without a `title.tik` file by providing the 32-character Title Key directly.
- **Automatic `keys.txt` Parsing:** Automatically searches for the correct Title Key in `keys.txt` based on the game's Title ID (checks game folder and parent directory).

## Termux One-Line Setup
Copy and paste this command into Termux to install `cdecrypt` automatically:

```bash
pkg update && pkg upgrade -y && pkg install -y git clang make && git clone https://github.com/manlemon223-prog/cdecrypt.git && cd cdecrypt && make && cp cdecrypt $PREFIX/bin/ && cd .. && rm -rf cdecrypt
```

## Usage

### 1. Fully Automatic
If you have `keys.txt` in your Download folder and a game folder (even with oddly named files):
```bash
cdecrypt "path/to/game_folder"
```

### 2. Manual Title Key
If you don't have a `title.tik` or `keys.txt`, you can provide the Title Key manually:
```bash
cdecrypt "path/to/game_folder" 1500E19891AF46763AB79D95C341D48B
```

## Build from Source
If you prefer to build manually:
```bash
git clone https://github.com/manlemon223-prog/cdecrypt.git
cd cdecrypt
make
```

## Credits
- Originally by **crediar**
- Maintained by **VitaSmith**
- Patched features by **manlemon223-prog**
