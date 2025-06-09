# 🧰 Untar
A simple C-based utility to extract .tar archive files, specifically designed to work with POSIX ustar formatted tarballs.
---
---
## 📁 Project Structure

```
.
├── inc
│   └── untar.h         # Header file for function declarations and struct definitions
├── main.c              # Entry point of the program
├── Makefile            # Build system to compile the project
├── minitalk.tar        # Sample tar archive to test with
├── src
│   ├── getters.c       # Tar header parsing logic (getters and helpers)
│   ├── process.c       # Main extraction logic
│   └── utils.c         # Utility functions (string handling, math, etc.)
└── untar               # Compiled executable after running make
```
---


## ⚙️ Features
Parses tar archive headers manually (no use of external libraries).

### Supports:

Extracting regular files

Reconstructing directory structure

Interpreting file permission modes

Handles padding/alignment as per 512-byte tar block format.


## 🚀 Build Instructions

```
make
```

This will compile main.c and the source files in src/ to produce the untar executable.


## 📦 Usage

```
./untar <filename>
```

This will extract the contents of minitalk.tar into the current directory.

## 🧠 How It Works

### Header Parsing:

Reads 512-byte blocks from the tar file.

Converts octal-encoded fields (e.g., size, mode) to decimal.

### File Extraction:

Recreates directories if needed.

Extracts file data and writes to the correct path.

Skips over padding to align with next 512-byte block.

### End-of-Archive Detection:

Stops extraction when it encounters two consecutive 512-byte blocks of all zeros.


## 📄 Header Fields Used

name – path and filename

mode – permissions (converted from octal)

size – file size (octal)

typeflag – type of entry (0 = regular file, 5 = directory)

## 🧪 Notes
Tested with tar files created using GNU tar and BSD tar.

Doesn’t support symlinks, device files, or extended GNU headers (yet).

Basic error handling for malformed archives.


## 📬 Author
Developed by levlow

Inspired by UNIX file archiving internals.
