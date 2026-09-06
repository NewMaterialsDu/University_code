print("{:-^25,}".format(123456789))  # ,表示千分位数
print("{:3f}".format(3.1415926))
print("{1:.5}".format("工商局很广泛化工色痕迹","过后就不会拒绝还款"))
print("{0:b}".format(276))
print("{0:c}".format(276))
print("{0:d}".format(276))
print("{0:x}".format(276))
print("{0:X}".format(276))
print("{0:o}".format(276))


  # 2为四舍五入到几位  3为字符串精确几位  
  # b: 二进制
  # c：对应的Unicode字符
   # d：十进制
   #x：小写16进制
   #X：大写16进制  obcdxX均为整数
   # o:八进制