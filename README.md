# Simulation de Banque

## Compilation et construction du programme
Le programme peut être compilé à l'aide de Make. 
* **make** - Compile et construit le programme sous le nom : **simuBanque**
* **make clean** - Nettoie l'exécutables et les binaires
* **make run** - Exécute un exemple du programme, avec des paramètres prédéfinis
* **make doxy** - Génère la documentation du programme

## Lancement du programme
L'exécutable, une fois créé avec make, se nomme **simuBanque**.
Le programme doit être lancé avec les options ci-dessous que celui-ci fonctionne. La liste des options peut être affichée dans le terminal à l'aide de l'option -help (ou -h).
* **-nc arg**              Défini le nombre de caissier de la simulation
* **-st arg1 arg2 ...**    Défini le temps moyen de service pour chaque caissier
* **-dp arg**              Défini la durée prévue de la simulation
* **-tm arg**              Défini le temps moyen d'arrivée

## Exemple
### Commande 
```
./simuBanque -nc 3 -st 1 1.2 1.4 -dp 1000 -tm 0.8
```

### Résultat
```
### Paramètres de la simulation ###
Durée de la simulation : 1000
Temps moyen entre chaque arrivée : 0.8
Nombre de caissier : 3
Temps moyen de services : 1, 1.2, 1.4  

### Résultats de la simulation ###
Durée réelle de la simulation : 1000
Clients servis durant la simulation : 1270
Taille max de la file d'attente : 7
Taille moyenne de la file d'attente : 2.82131
Temps d'attente moyen dans la file d'attente : 0.229134

Caissier n°0 : 
Taux d'occupation : 56.7
Nombre de clients servis : 665

Caissier n°1 : 
Taux d'occupation : 34.7
Nombre de clients servis : 410

Caissier n°2 : 
Taux d'occupation : 18.4
Nombre de clients servis : 195
```
