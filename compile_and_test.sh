# H1: Run the file, and run it against the test cases
contest='1918'
problem_name='D_blocking_elements'


# H2: Compile the file
# C:/msys64/ucrt64/bin/g++.exe -Wall -Wextra -g3 c:/Users/Efe/Documents/Github/CodeForces/$contest/$problem_name.cpp -o c:/Users/Efe/Documents/Github/CodeForces/$contest/output/$problem_name.exe
rm c:/Users/Efe/Documents/Github/CodeForces/$contest/output/git_bash/$problem_name.exe
g++ c:/Users/Efe/Documents/Github/CodeForces/$contest/$problem_name.cpp -o c:/Users/Efe/Documents/Github/CodeForces/$contest/output/git_bash/$problem_name.exe


# H2: Run it
cd 'c:/Users/Efe/Documents/Github/CodeForces/'$contest'/output/'
## MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL="*" ./$problem_name'.exe' < '../../test_cases/'$problem_name'_inputs.txt' 1> ../out.txt 2> out_extra.txt
./git_bash/$problem_name'.exe' < '../test_cases/'$problem_name'_inputs.txt' 1> out.txt 2> out_extra.txt

# Note: Outputs are in outputs/out.txt, debug logs are in outputs/out_extra.txt

# H2: Check to ensure the outputs are correct
cd 'c:/Users/Efe/Documents/Github/CodeForces/'
python check_output.py ./$contest/test_cases/$problem_name'_outputs.txt' ./$contest/output/out.txt