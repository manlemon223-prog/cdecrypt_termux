# cdecrypt_termux (Smart Edition)

A Wii U NUS content file decrypter patched for Termux/Android. This version is designed to be "smart"—it finds your folders and keys so you don't have to.

## Smart Features
- **Fuzzy Folder Finder:** Just type the folder name. If it's not in your current directory, `cdecrypt` will automatically search for it in `/sdcard/Download/`.
- **Global Key Search:** Place one `keys.txt` in your `/sdcard/Download/` folder, and `cdecrypt` will find the correct Title Key for any game automatically.
- **Auto-Discovery:** Automatically finds TMD and Ticket files even if they have non-standard names (e.g., `tmd.17` or `cetk`).
- **Manual Key Support:** Decrypt games without a `title.tik` file by providing the 32-character Title Key directly.
- **Multi-Decrypt Logic:** Automatically detects if the provided key is encrypted (common in databases) and self-corrects if needed.
- **Auto-Cleanup:** Automatically deletes encrypted `.app`, `.h3`, and TMD/Ticket files after a successful decryption to save storage space.

## Termux One-Line Setup
Copy and paste this command into Termux to install `cdecrypt` automatically:

```bash
pkg update && pkg upgrade -y && pkg install -y git clang make && git clone https://github.com/manlemon223-prog/cdecrypt_termux.git && cd cdecrypt_termux && make && cp cdecrypt $PREFIX/bin/ && cd .. && rm -rf cdecrypt_termux
```

## Usage

### 1. The Easy Way (Folder Name Only)
If your game folder is in `/sdcard/Download/`, you can just type its name:
```bash
cdecrypt "Game Folder Name"
```
*Note: Always use **"quotes"** if the folder name has spaces or parentheses ( ) to avoid shell errors.*

### 2. Manual Path
```bash
cdecrypt "/sdcard/Download/MyGame"
```

### 3. Manual Title Key
If you don't have a `keys.txt`, you can provide the Title Key manually:
```bash
cdecrypt "Game Folder" 1500E19891AF46763AB79D95C341D48B
```

## Credits
- Originally by **crediar**
- Maintained by **VitaSmith**
- Smart features & Android patches by **manlemon223-prog**
