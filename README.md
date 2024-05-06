Auteur : Paul-Etienne Rétaux

Professeur : Monsieur Stéphane Zuckerman (laboratoire ETIS)

Ce projet a été réalisé de septembre 2023 à mars 2024 dans le cadre du Master Systèmes Intelligents et Communicants proposé par l'ENSEA et la faculté de Cergy-Pontoise. 
Le projet consiste à distribuer le calcul d'un NAS parallel benchmark (le Embarassingly Parallel classe S : https://www.nas.nasa.gov/software/npb.html ) sur deux Raspberry Pis en allouant à chacune un nombre de MPI
slots en adéquation avec l'occupation des ressources en cours (e.g. si une des Raspberrys a plus de 75 % de charge CPU, elle ne se verra allouer aucun slot; en revanche, si la charge est de moins de 25 %, elle se verra allouer trois slots).
L'occupation de ces deux noeuds varie en effet avec le temps car une boucle for de 1000 itérations se réveille toutes les secondes sur chaque RPi. 

Enfin, deux noeuds "clients" récupèrent les informations de disponibilité des Raspberry Pis, tout cela grâce au protocole MQTT. Cela n'a pas d'intérêt pour le moment mais dans une vision de "Smart Buildings" 
basés sur l'Edge Computing, ces noeuds clients pourraient être des thermostats qui font exécuter leurs calculs sur des petits serveurs locaux.
