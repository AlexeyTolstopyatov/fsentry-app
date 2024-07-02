# File System Entries Watcher (fsentry-app)
Written using Windows API. For Windows 8/11. The general goal of the project is to explore paths that cannot be accessed through Microsoft Windows Explorer.

### Absolute Paths?
In this text ```Absolute path``` is not normalized way to file. 
Example:
```
\\?\GLOBALROOT\Devices\PhysicalDrive0\LogicalDisk0\Windows\SysWOW64
```

Using paths, you can call old devices like COM mouse (:D), just write it
```
\\.\COM1\
```

# My Refactor rules
 - Windows API handles uses "h" prefix (```hFile```)
 - Classes uses "C" prefix (```CFile```)
 - Functions/Procedures use CamelCase, just because, except Windows API functions i dont use. (```GetFileSystemEntries```)
 - Function/Procedure arguments use C-like style. (not widestring. ```wstr```, not file_name, ```fname```)
 - Headers use C-like style naming. ("fstring", "fsprocessing")
 - Function/Procedure descriptions stores in ```.h``` (header) files.


I hope 'll understood what the entries contains in those paths...
