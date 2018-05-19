*********BONUS*********
----------------------------

OK -> :ballot_box_with_check:

KO -> :black_square_button:


| Fichier de scene                              |     |
|:-----------------------------------------------|:-----:|
| Il y a un fichier de description de la scene. | :ballot_box_with_check: |

| Fichier ++                                                                                                                                                                                                |     |
|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:-----:|
| Le fichier est en XML, ou en tout cas dispose d'une structure spéciale, d'une hiérarchie.. <br />Bref, pas un simple fichier avec 1 objet par ligne ou des blocs basiques par objet séparés par une ligne vide. | :ballot_box_with_check: |

| Ambiance ++ | |
|:-------------|:-:|
| Si la lumiere d'ambiance est pas en dur dans le code mais reglable dans le fichier de conf. | :ballot_box_with_check: |

|Objets limites | |
|:--------------|:-:|
| On peut decouper basiquement les objets selon les axes x,y,z | :black_square_button: |
| On peut choisir de decouper au chois en position simple ou en position reelle (un cylindre penché est soit découpé selon son axe de revolution propre, soit selon un vrai axe) | :black_square_button: |
| Rotation et translation fonctionnent correctement apres la découpe | :black_square_button: |
| Le processus de découpe est unique pour tous les objets, et pas dupliqué pour chaque type d'objet. | :black_square_button: |
| Pour le plan on peut decouper autrement que sur les axes ( si vous faites une limite sur x et y, ca vous fait deja un carre) : un triangle, et/ou un disque par ex. | :black_square_button: |


| Perturbations | |
|:--------------|:-:|
| Perturbation de la normale : genre avec un sinus, ca donne l'impression d'avoir des vaguelettes | :ballot_box_with_check: |
| Perturbation de la couleur : un damier (qui n'a pas une double case sur l'axe des X ou des Y) | :ballot_box_with_check: |
| Perturbation de la couleur : un algo un peu plus complique pour changer la couleur de l'objet | :ballot_box_with_check: |
| Perturbation de la couleur : un algo super complexe, genre bruit de Perlin : comptez 2 points, et si il n'y a que celui-la, ne comptez pas le point precedent. | :ballot_box_with_check: |

| Lumiere directe | |
|:----------------|:-:|
| On est ébloui par les spots en face de nous. | :black_square_button: |

| Lumiere parallele | |
|:------------------|:-:|
| Une lumiere parallèle eclaire la scene, selon une direction precise. (a contrario d'un spot qui emet de la lumiere d'un point precis) | :black_square_button: |

| Reflexion et transparence | |
|:--------------------------|:-:|
| La reflexion marche, on a bien un effet mirroir | :ballot_box_with_check: |
| On peut changer le % de reflexion (c'est pas du tout ou rien) | :ballot_box_with_check: |
| La transparence fonctionne, on voit au travers | :ballot_box_with_check: |
| L'indice de refraction fonctionne (au besoin demander a voir la formule de Descartes dans le code) | :ballot_box_with_check: |
| On peut changer le % de transparence | :ballot_box_with_check: |

| Ombres et transparence | |
|:-----------------------|:-:|
| Selon la transparence d'un objet, est-ce que son ombre s'éclaircit/s'assombrit ? | :black_square_button: |

| Textures | |
|:---------|:-:|
| On peut appliquer une texture sur au moins un des 4 objets | :ballot_box_with_check: |
| On peut appliquer une texture sur les 4 objets | :ballot_box_with_check: |
| On peut etirer (ou le contraire) une texture sur un objet | :ballot_box_with_check: |
| On peut decaler une texture sur un objet | :ballot_box_with_check: |
| Utilisation d'une lib autre que la minilibX et ses xpm pour charger les textures (jpeg, png, ...) | :ballot_box_with_check: |

| Autres applications des textures | |
|:---------------------------------|:-:|
| La texture sert a modifier la normale d'un objet (du bump mapping en gros) | :ballot_box_with_check: |
| La texture sert a modifier la transparence d'un objet a certains endroits | :black_square_button: |
| La texture sert a definir la limite ou la decoupe d'un objet | :black_square_button: |
| La texture sur un objet semi-transparent sert de diapositive et se trouve projetee sur d'autres objets (2 points) | :black_square_button: |

| Objets composes | |
|:----------------|:-:|
| On peut définir un objet composé d'autres objets :<br />un cube == 6 plan limités<br />un verre == un cone+un cylindre+une sphere (tous limités)<br />Et il est possible de definir notre scene avec plusieurs fois le meme objet composé mais a des positions et avec des orientations diverses (si c'est pas le cas, en fait il sert a rien l'objet compose...) | :ballot_box_with_check: |

| Objets negatifs | |
|:----------------|:-:|
| On peut soustraire un objet a un autre ou deformer un objet par un autre.<br />=> une sphere negative qui fait un trou dans un plan<br />=> un cylindre vient deformer un autre cylindre perpendiculaire jusqu'au centre. | :black_square_button: |

| Objets natifs simples | |
|:----------------------|:-:|
| Principalement ce qui peut se resoudre avec un degre de complexite inferieur ou egal a la sphere/cylindre/cone (qui sont de degres 2)<br />=> principalement paraboloide et hyperboloide.<br />Si il y a au moins un objet de cette nature, alors c'est OK. | :ballot_box_with_check: |

| Effets visuels classiques | |
|:--------------------------|:-:|
| Antialiasing | :black_square_button: |
| Effet Cartoon | :ballot_box_with_check: |
| Motion blur | :black_square_button: |
| Sepia ou autre filtre de couleur | :ballot_box_with_check: |
| Stereoscopie simple (genre lunettes rouges/vertes)| :ballot_box_with_check: |

| Effets techniques | |
|:------------------|:-:|
| Calcul cluster sur plusieurs machines (2pt) | :black_square_button: |
| Calcul multi thread | :ballot_box_with_check: |
| C'est PARTICULIEREMENT rapide comme rendu | :black_square_button: |
| Sauvegarde de l'image integree au RT| :ballot_box_with_check: |

| Environnement | |
|:--------------|:-:|
| Il y a une interface sommaire : un message d'attente graphique, ou une barre de progression .. Bref autre chose que du message dans un terminal | :ballot_box_with_check: |
| Il y a une interface chiadee (en gtk, ou QT par ex. avec des elements configurables : chargement du fichier, controle du rendu, etc..) (compter ici le point precedent egalement) | :ballot_box_with_check: |
| On peut effectuer des modifications de la scene en live (position de l'oeil ou des objets, couleurs ou textures..) sans devoir relancer le programme | :ballot_box_with_check: |
| On peut parametrer plusieurs rendus automatiquement avec des changements d'un rendu a l'autre (pas forcement avec une super interface, on accepte aussi si c'est une serie de scripts qui font ca tout seuls) | :ballot_box_with_check: |
| On peut generer automatiquement des objets pour une scene : un torre realise avec tout plein de spheres, une helice genre de l'ADN avec des spheres et des cylindres.. | :black_square_button: |

| Objets Exotiques | |
|:-----------------|:-:|
| Cube troue | :black_square_button: |
| Nappe | :black_square_button: |
| Torre | :black_square_button: |
| Resolution d'equation quelconque fournie dans le fichier de conf (genre avec la lib GNU qui fait ca bien) | :black_square_button: |
| Autre (objets fractals, etc...) autant de fois que necessaire jusqu'a 5 max bien sur | :black_square_button: |

| En vrac | |
|:--------|:-:|
| Une sequence video realisee avec votre RT ! (mettez le lien dans le forum) | :ballot_box_with_check: |
| Fichiers modelers : vous importez les fichiers pov ou 3ds (par ex), et les rendez dans votre RT. | :black_square_button: |
| En relief sur une TV 3D ou sur un OculusRift ! | :black_square_button: |
| Spot non ponctuel : tel un filament d'ampoule, la source lumineuse n'est pas ponctuelle, et du coup les ombres n'ont pas un contour net. | :black_square_button: |
| D'autres trucs delirants. | :ballot_box_with_check: |

| Le ruban de Moebius | |
|:--------------------|:-:|
| Un joli ruban de Moebius !! | :black_square_button: |

| Caustics et/ou Global illumination | |
|:-----------------------------------|:-:|
| Ca c'est cool. Mailez-moi, postez des images dans le forum, tout ca. | :black_square_button: |
