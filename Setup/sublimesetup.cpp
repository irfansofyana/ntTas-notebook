{
 "cmd": ["g++", "-std=c++11", "$file_name", "-o", "${file_base_name}.exe", "&&", "start", "cmd", "/k" , "$file_base_name"],
 "selector": "source.cpp",
 "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
 "working_dir": "${file_path}",
 "shell": true
}