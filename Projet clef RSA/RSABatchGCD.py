import os
import base64
import sys
import numpy as np
import math
from math import prod, floor, gcd

clear = 'clear'
Clef = []
Clef_Int = []
Doublon = []
NbDoublon = len(Doublon)
resultat_gcd = []
i = 0
j = 0

def affiche_doublon(): # dit si nous avons trouver un doublon ou pas
    if NbDoublon == 0:
        print("Pas de doublon")
    if NbDoublon !=0:
        print('Doublon Trouvé')
        for k in range(NbDoublon): # si un ou plusieurs doublon ont étaient trouver permets de les afficher
            print(Doublon[k])

def Format_Clef():
    for g in range(tailleClef):
        NEW_key = Clef[g].replace("-----BEGIN PRIVATE KEY-----", "") #cette ligne et la suivante permette d'enlever deux lignes dans la clef pour permettre ensuite de convertir la clef
        NEW_key = NEW_key.replace("-----END PRIVATE KEY-----", "")
        Clef[g] = NEW_key # change la clef la ou elle est stocker
        print(Clef[g])
        #Clef[g] = int.from_bytes((base64.b64decode(Clef[g])), byteorder="big",)
        Clef[g] = int(base64.b64decode(Clef[g]).hex(),base = 16)#nous permets de convertir la clef de string en base64 puis de base64 en hexadecimal et finalement d'hexadécimal en int
        Clef_Int.append(Clef[g]) # stockage de la nouvelle valeur de la clef

def producttree(X): # cette fonction permets de multiplier par pairs et ensuite les pairs obtenue entre elles
    result = [X]
    while len(X) > 1:
        X = [prod(X[int(i*2): int((i+1)*2)]) for i in range((len(X)+1)//2)]
        result.append(X)
    return result

def batchgcd_faster(X): #effectuer le carre du noeud actuelle du productree actuel
    prods = producttree(X)
    R = prods.pop()
    while prods:
        X = prods.pop()
        R = [R[floor(i/2)] % X[i]**2 for i in range(len(X))]
    return [gcd(r//n,n) for r,n in zip(R,X)]

file_out = open("rsa_key.txt", "w")
for i in range(250000): #boucle permettant de choisir le nombre de clés à crées
    tailleClef = len(Clef)
    key = os.popen('openssl genrsa 512').read()# génération et stockage d'une clé dans la variable key
    file_out.write(key)
    token = 0 # cette variable permets de savoir quand nous avons eu un doublon et si la clé actuel est la première génére
    if tailleClef == 0: # stockage de la première clé car le tableau est actuellement de taille 0
        Clef.append(key)
        tailleClef = len(Clef)
        token = 1 # empêche de stocker deux fois la première clef
    for j in range(tailleClef): #boucle permettant de parcourir tout le tableau Clef
        if key == Clef[j] and j != 0: #permet de voir si la clé est un doublon
            NbDoublon +=1
            Doublon.append(key)
            NbDoublon = len(Doublon)
            Clef.append(key)
            tailleClef = len(Clef) #actualisation de la valeur permettant de connaitre la taille du tableau Clef
            token = 1
    if token == 0: # stockage normal de la clef si elle n'est pas un doublon
        Clef.append(key)
        tailleClef = len(Clef)
    print(Clef[i])

#os.system(clear)

affiche_doublon()
Format_Clef() # permet de changer le format des clefs et ensuite de les convertir de string à int
resultat_gcd = batchgcd_faster(Clef_Int) #appelle de fct permettant d'effectuer le batchGCD
print(resultat_gcd)
file_out.close()