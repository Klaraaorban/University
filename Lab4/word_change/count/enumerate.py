def find_count(filename, word):
    f = open(filename, 'r')
    count = 0

    for line in f:
        words = line.split(' ')

        for w in words:
            if word == w.strip():
                count += 1

    f.close()
    return count
