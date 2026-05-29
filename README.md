# randcout
A simple terminal utility for random output to the terminal.
# just install:
1. go to the releases page
2. download latest versoin for your linux distro
3. install package (for ubuntu/debian sudo dpkg -i randcout_(version).deb or sudo apt install ./randcout_(version).deb)
4. type randcout 100
# Install compile:
1. download randcout.c
2. to compile use gcc -O2 -o randcout randcout.c
3. optional:
4. sudo cp randcout /usr/local/bin/ 
5. sudo chmod +x /usr/local/bin/randcout

# use
./randcout 200
generating random symbols with speed 200chars/sec.
./randcout <chars/sec>
