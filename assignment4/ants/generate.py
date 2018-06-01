import os, sys

ants = ["Harvester", "Thrower", "Fire", "LongThrower", "ShortThrower", "Wall", "Ninja", "Bodyguard"]

for ant in ants:
    os.system("sed -i 's/{0}/{0}_HPP/g' {1}.hpp".format(ant.upper(), ant.lower()))
