ants = ["Thrower", "Fire", "LongThrower", "ShortThrower", "Wall", "Ninja", "Bodyguard"]

with open("Makefile", "a") as f:
    for ant in ants:
        f.write("{0}.o: ants/{0}.cpp ants/{0}.hpp\n".format(ant.lower()))
        f.write("\t$(CC) $(C_FLAGS) -c ants/{}.cpp\n\n".format(ant.lower()))
