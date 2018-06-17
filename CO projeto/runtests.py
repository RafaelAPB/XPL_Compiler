import glob
import subprocess
import os, sys

#Folder
#   tests
#   expected
#   xpl


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

alltests = glob.glob("tests/*.xpl")
alltests.sort();
#subprocess.call(["make", "clean"], cwd="./xpl")
subprocess.call(["make"], cwd="./xpl")

i = 0
tests_passed = 0;
while i < len(alltests):
	result = alltests[i].replace("tests","results/asm").replace(".xpl",".asm")
	test = alltests[i]
	subprocess.call(["./xpl/xpl", test, "-o", result])
	subprocess.call(["yasm", "-felf32", result, "-o", test.replace("tests","results/o").replace(".xpl",".o")])
	subprocess.call(["ld", "-melf_i386" ,"-o", test.replace("tests","results/exe").replace(".xpl",""), test.replace("tests","results/o").replace(".xpl",".o"),"-L/home/rafael/Transferências/librts4-201602111900", "-lrts"])

	with open("./" + test.replace("tests","results").replace(".xpl",".txt"), 'a+') as file:
		subprocess.call(["./" + test.replace("tests","results/exe").replace(".xpl","")], stdout = file)


	my_file = open("./" + test.replace("tests","results").replace(".xpl",".txt"), 'r')
	david_file = open(test.replace("tests","./expected").replace(".xpl",".out"), 'r')


	david_output =  "".join(david_file.read().split())
	my_output = "".join(my_file.read().split())

	my_file.close()
	david_file.close()

	print(alltests[i])
	i += 1
	if (david_output.strip(" \n\r\t") == my_output.strip(" \n\r\t")):
		print(bcolors.OKGREEN + "Test success" + bcolors.ENDC)
		tests_passed += 1
	else:
		print(bcolors.WARNING + "Test failed" + bcolors.ENDC)
		subprocess.call(["colordiff", test.replace("tests","./expected").replace(".xpl",".out"), test.replace("tests","./results").replace(".xpl",".txt")])


print("\n" + str(tests_passed/len(alltests) * 100) + "% tests passed")
