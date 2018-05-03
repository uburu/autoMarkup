import word2vec

data_path = "data/"
w2v_file = "w2v_file.bin"
train_file = "train.txt"

file = open(data_path + train_file, "r")
text = file.read().lower()
file.close()
file = open(data_path + train_file, "w")
file.write(text)
file.close()

print("Обучаюсь...")
word2vec.word2vec(data_path + train_file, data_path + w2v_file, size=1000, window=50, min_count=50)
print("Готово!")
