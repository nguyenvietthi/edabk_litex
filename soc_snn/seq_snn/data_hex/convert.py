def binToHexa(n, indexs):
    
    # convert binary to int
    num = int(n, 2)
      
    # convert int to hexadecimal
    hex_num = ("{0:0>" + indexs + "X}").format(num, 'x')
    return(hex_num)

fr = open("../data/csram.mem", "r")
fw = open("csram.mem", "w")
for x in fr:
  print(binToHexa(x, '92'))
  fw.write(binToHexa(x, '92')+'\n')

fr.close()
fw.close()

fr = open("../data/tb_input.txt", "r")
fw = open("tb_input.txt", "w")
for x in fr:
  print(binToHexa(x,'5'))
  fw.write(binToHexa(x, '5')+'\n')

fr.close()
fw.close()
