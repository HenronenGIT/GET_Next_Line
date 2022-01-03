#Run leaks detecting tool
leaks -atExit -- ./get_next_line | grep LEAK:
