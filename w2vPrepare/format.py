import word2vec
fname = "history-w2v_200.bin"
model = word2vec.load(fname)
data = [(i, model.vocab[i], model.vectors[i]) for i in range(len(model.vocab))]
file = open("test.txt", "w")
for i in range(1,len(data)):
	str_write = ""
	str_write += str(data[i][0])
	str_write += " "
	str_write += str(data[i][1])
	str_write += " "
	arr_str = ""
	for ind, j in enumerate(data[i][2]):
		arr_str += str(j)
		if ind <= len(data[0][2]) - 2:
			arr_str += ","
	file.write(str_write + arr_str + "\n" )
    # file.write(arr_str + "\n")

