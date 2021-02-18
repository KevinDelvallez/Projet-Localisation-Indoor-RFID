
% FONCTION CONTROLE
% KEVIN DELVALLEZ MEA3
% AURELIEN GORI MEA3


function u = controle(Etat,arrivee,capteurs)
     
     %% INITIALISATION DES VARIABLES 
     
     global R L wmax dmax Nmin Thetamin % On récupère les variables globales définis dans le main
    
     % On inverse la position du capteur 1 et 3 dans la matrice pour
     % correspondre avec nos conditions et nos valeurs
     dist = [capteurs(3,1) capteurs(3,2);capteurs(2,1) capteurs(2,2);capteurs(1,1) capteurs(1,2)];

     coef_vitesse = 1.5; % coefficient permettant de régler la vitesse max du robot
     fin = 0; % variable permettant de savoir si on est sur l'arrivee (lorsqu'il vaut 1)

     arrivee(3) = mod(arrivee(3),2*pi); % On définit l'angle d'arrivée entre -2*pi et 2*pi
     if(arrivee(3)<0)
         arrivee(3) = arrivee(3) + 2*pi; % on définit l'angle d'arrivee entre 0 et 2*pi
     end
     
     %init capteurs
     rob.porte = dmax;                     %Porté max du capteur
     rob.pc1 = rob.porte;                 %porté capteur 1
     rob.pc2 = rob.porte;                 %porté capteur 2
     rob.pc3 = rob.porte;                 %porté capteur 3
     
     %init du robot
     rob.dist_fin_max = Nmin;     %Distance maximum autorisé enre le robot et l'arrivée pour stopper le programme
     rob.R = R;                %rayon des roues
     rob.L = L;                 %Demi-entracte entre les roues
     rob.X = Etat(1);             %X et Y position initiale
     rob.Y = Etat(2);
     rob.theta = Etat(3);         %Angle du robot
     rob.H = 0.8;                 %Longueur du robot
     rob.wd = 0;                  %vitesse angulaire de la roue droite
     rob.wg = 0;                  %vitesse angulaire de la roue gauche
     
     %Matrice de passage pour calculer les vitesses angulaires des roues a
     %partir de la vitesse linéaire et angulaire du robot
     P = [[rob.R/2 rob.R/2];[rob.R/rob.L -rob.R/rob.L]];
     
     %% CALCULE VITESSE : ALIGNEMENT AVEC L'ARRIVEE
     
     %calcul de l'angle d'arrivée par rapport aux abscisses 
     v_point = [arrivee(1)-rob.X arrivee(2)-rob.Y];
     ang_arrivee = atan2(v_point(2),v_point(1));
     %Calcul du première angle entre le robot et l'arrivée : l'angle
     %orienté part de l'arrivée pour aller vers le robot
     angle1 = rob.theta - ang_arrivee;
     
     %Calcul du second angle orienté : abs(angle1) + abs(angle2) = 2*pi
     if(angle1>0)
         angle2 = angle1 - 2*pi;
     else
         angle2 = angle1 + 2*pi;
     end
     %On prend l'angle le plus petit des deux : le chemin le plus court
     if(abs(angle2)<abs(angle1))
         ang = angle2;
     else
         ang = angle1;
     end
     
     % Déviation du robot par rapport à l'angle orienté calculé
     if(ang<0)
         v(2)= (coef_vitesse)*abs(ang);          %Si l'angle est négatif on tourne à gauche
         vitesse_angulaire_direction_arrivee = v(2); % On garde cette valeur de vitesse pour plus tard (lorsqu'on est proche de l'arrivee)
     else
         if(ang>0)
             v(2)=-(coef_vitesse)*abs(ang);      %Si l'angle est positif on tourne à droite
             vitesse_angulaire_direction_arrivee = v(2);
         else
             v(2) = 0;                  %Si l'angle est nul on ne tourne pas
             vitesse_angulaire_direction_arrivee = v(2);
         end
     end
     
     %% CALCUL DE VITESSE : EVITEMENT OBSTACLES
     
     % Déviation du robot par rapport à la détection d'obstacle
     %Cette déviation est prioritaire sur celle de l'angle orienté
     if(dist(1,1)<rob.porte && dist(3,1)<rob.porte)
         %Si les deux cateurs sur le coté détectent deux (ou un) obstacles,
         %la vitesse est proportionnelle à la différence entre les
         %distances de detection
         v(2) = 0.2*(dist(1,1)-dist(3,1));
         
         if(dist(2,1)<rob.porte)
             %Si les trois capteurs détectent, on tourne jusqu'à libérer un
             %capteur (trouver un sortie)
             v(1) = 0;
             v(2) = 1;
         end
     else
         if(dist(1,1)<rob.porte)
             %Si le capteur gauche detecte on tourne à droite
             v(2) = -(coef_vitesse)/dist(1,1);
         else
             if(dist(3,1)<rob.porte)
                 %Si le capteur droit detecte on tourne à gauche
                v(2) = (coef_vitesse)/dist(3,1);
             else
                 v(2) = vitesse_angulaire_direction_arrivee; % si aucun capteur detecte on tourne pour s'aligner à l'arrivée
             end
         end
     end
     
     if(dist(2,1)<1)
         %Si le capteur du milieu detecte un obstacle tres proche, on
         %s'arrête et on tourne ...
         v(1) = 0;
         v(2) = 1; %... à droite
     else
         %Sinon le robot avance proportionnellement à la distance du lazer
         %du mileu
        v(1) = (coef_vitesse/rob.porte)*dist(2,1);
     end
     
     %% POINT ARRIVEE
     
     distance_arrivee = sqrt(v_point(1)^2+v_point(2)^2);  %distance entre le robot et l'arrivee
     if(rob.X <= arrivee(1)+ dist(2,1) && rob.X>=arrivee(1)-dist(2,1) &&...
             rob.Y <= arrivee(2)+dist(2,1) && rob.Y>=arrivee(2)-dist(2,1) &&...
             distance_arrivee<dist(2,1) && distance_arrivee<dist(1,1) &&...
             distance_arrivee<dist(3,1))
         %Si le robot est proche de l'arrivee et qu'il n'y a pas d'obstacle
         %entre eux alors on ne tient plus compte des obstacles
         v(2) = 2.5*vitesse_angulaire_direction_arrivee;
         v(1) = 0.6;
     end
     
     if(rob.X <= arrivee(1)+rob.dist_fin_max && ...
             rob.X>=arrivee(1)-rob.dist_fin_max &&...
             rob.Y <= arrivee(2)+rob.dist_fin_max ...
             && rob.Y>=arrivee(2)-rob.dist_fin_max)
         %Si le robot arrive au point d'arrivée on arrête 
         fin = 1;
         v(1) = 0;
         v(2) = 0;
         %Cependant, si le robot n'est pas à l'angle d'arrivee demandé
         %alors on le fais tourner jusqu'à l'atteindre
         if(abs(rob.theta-arrivee(3))>Thetamin)
             ang_rob_arrivee = rob.theta-arrivee(3); % première angle orianté entre le robot et l'angle d'arrivee demandé
             ang_rob_arrivee2 = 0; % second angle orienté
             % On utilise pour calculer la vitesse angulaire exactement la
             % même méthode pour celui permettant de calculer la vitesse
             % angulaire nécessaire pour s'aligner avec l'arrivee (ligne 31
             % à 62). L'angle orienté part de l'arrivee pour aller vers le
             % robot.
             % On calcule le second angle orienté
             if(ang_rob_arrivee<0)
                 ang_rob_arrivee2 = ang_rob_arrivee + 2*pi;
             else if(ang_rob_arrivee>0)
                     ang_rob_arrivee2 = ang_rob_arrivee - 2*pi;
                 end
             end
             % On garde l'angle le plus petit des deux (le chemin le plus
             % court)
             if(abs(ang_rob_arrivee2)<abs(ang_rob_arrivee))
                 ang_final = ang_rob_arrivee2;
             else
                 ang_final = ang_rob_arrivee;
             end
             v(1) = 0;
             v(2) = -1*(ang_final)/abs(ang_final); % Si l'angle est negatif on tourne à droite, sinon à gauche
         end
     end
     
     %% CONVERSION DES VITESSES
     
     % Conversion de vitesse du robot vers vitesses angulaires des roues
     u = inv(P)*(v');
     
     % On veut maintenant que la vitesse des roues maximale soit égal à 10
     % Pour se faire, on met la vitesse angulaire la plus grande des deux à
     % 10. Si cette vitesse a diminué (augmenté) alors on diminue
     % (augmente) la second vitesse proportionnellement
     if(u(1)>=u(2) && fin == 0)
         proportion = wmax/u(1); % on calcul le coef de proportionnalité
         u(1) = wmax; % On met la valeur la vitesse la plus grande à 10
         u(2) = proportion*u(2); % on ajuste la seconde vitesse
     else if(u(1)<=u(2) && fin == 0)
             % On fais de même que précédement 
             proportion = wmax/u(2);
             u(2) = wmax;
             u(1) = proportion*u(1);
         end
     end
     
end