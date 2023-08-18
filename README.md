#  Simple Shell

This program is a simple implementation of a shell that can accept user input, parse the input into separate commands and arguments, and execute the specified command.
It uses the getpatharray function to retrieve the directories specified by the PATH environment variable and it uses the check_cmd function to search for the specified command in those directories.

## Showcase
Here is a quick demonstration of _printf in action:

```
 ./hsh
 $ ls
 bin  boot  dev  etc  hello_world  home  lib  lib32  lib64  libx32  media  mnt  opt  preprocessor  proc  root  run  sbin  srv  sys  tmp  usr  var  welcome  y
 $
```


```
 ./hsh
 $ pwd
 root@bd5438578880:~/holbertonschool-simple_shell#
 $
```


```
 ./hsh
 $ /bin/ls
 bin  boot  dev  etc  hello_world  home  lib  lib32  lib64  libx32  media  mnt  opt  preprocessor  proc  root  run  sbin  srv  sys  tmp  usr  var  welcome  y
 $
```
 ```
 ./hsh
 $ env
 HOSTNAME=bd5438578880
 LANGUAGE=en_US:en
 PWD=/root/holbertonschool-simple_shell
 TZ=America/Los_Angeles
 HOME=/root
 LANG=en_US.UTF-8
 LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
 LESSCLOSE=/usr/bin/lesspipe %s %s
 TERM=xterm
 LESSOPEN=| /usr/bin/lesspipe %s
 SHLVL=1
 LC_ALL=en_US.UTF-8
 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
 OLDPWD=/root
 _=/usr/bin/env
 root@bd543857888
 $
```


## Prerequisites
Compiled on Ubuntu 20.04 LTS*

* Include the "shell.h" header file in main program. Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* Hndling the “end of file” condition (Ctrl+D).
* Hanling the command line with arguments.
* Handle the PATH.
* Support the exit features and the exit status.
* Handling the command seperator.
* Support the file input.

###   Features

    Accepts user input and parses it into separate commands and arguments
    Retrieves the directories specified by the PATH environment variable using the getpatharray function
    Searches for the specified command in the directories using the check_cmd function
    Creates a child process to execute the specified command
    Handles errors and provides feedback to the user, such as printing an error message when a command is not found

## Requirements
- Allowed editors: vi, vim, emacs
- All the files will be compiled on Ubuntu 20.04 LTS
- No more than 5 functions per file

## File Descriptions
- buff_fork.c: contains a function to create a buffer from the tokenized input and another to create the child procces to excecute the given command
- exec.c : cointains the execute command function and a custom function to print env variables
- find.c : cointains functions in order to check the status of the raw input and the input in the env $PATH
- simple_shell.c : the main function that contains the main loop
- shell.h : header file, contains all the prototypes for the files

### Usage

 Enter any valid command, such as ls or pwd, and the program will search for it in the directories specified by the PATH environment variable.
If the command is found, the program will create a child process to execute it. If the command is not found, an error message will be printed.

To exit the program, the user can enter the exit command at the prompt, or pressing the combination **Ctrl. + d** . This will cause the program to terminate and free any allocated memory.

## Flowchart
 <img src="https://github.com/JOTALGS/holbertonschool-simple_shell/blob/main/shell%20FCh.png" alt="Flowchart" border="0">

## Authors

* **Franco Musso** - *Holberton Student* - [Franco Musso](https://github.com/FrancoMuVa)
* **Jose Gil** - *Holberton Student* - [Jose Gil](https://github.com/JOTALGS)
