from random import randint

letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
           'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']


def Name():
    l = randint(1, 10)
    name = ""
    for i in xrange(l):
        index = randint(0, 25)
        name += letters[index]
    return name


def Sex():
    l = randint(0, 1)
    if l == 0:
        return 'm'
    else:
        return 'w'


def randomId():
    sid = ""
    for i in xrange(8):
        sid += str(randint(0, 9))
    return sid


def Phone():
    phone = ""
    for i in xrange(11):
        phone += str(randint(0, 9))
    return phone

if __name__ == "__main__":
    fo = open("./info.csv", 'a')
    for i in xrange(80):
        personInfo = Name() + ',' + Sex() + ',' + randomId() + ',' + Phone() + '\n'
        fo.write(personInfo)
    fo.close()
