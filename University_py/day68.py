

f = "C:/Users/Windows/Desktop/student/new_lines.txt"
a = open(f,"w") 

ls = ["中华","人们","共和国","中央人民政府"]
a.writelines(ls)
a.close()

