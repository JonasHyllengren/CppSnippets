# terminal shortcuts
ctrl+a # beginning of line
ctrl+e # end of line
crtl+k # delete from here to line end
history [N] # prints the last N commands
./[bash].sh -x # x-flag prints additional info
 
more [file.txt] # print file
tail [file.txt] # print end of file
# hold ctrl to move faster with arrow buttons!

# firefox
ctrl+tab # next tab
ctrl-shift+tab # previous tab
ctrl+w # close tab
alt+[<-] # backwards
alt+[->] # forward

# ls
ls -a # hidden
ls -l # details
ls -s # size

# grep
grep --help | grep invert # show all help regarding "invert"

# find
find [folder] -name [filename.fileending]
find [folder] -iname # case insensitive

# processes
pstree -u [user] -pca # display current processes
kill -9 [APP_ID] # kill process (get appID from e.g. pstree
kill [PID]
ps -t # display processes

# other
xdg-open [file] # open file with default program
echo $? # print status of last ocmmand (0==good)


