function xdot = Modele(t,x,u,rob)
    tau = 0.1;  %Temps de réponse des moteurs du robot
    xdot(1) = ((x(4)+x(5))/2)*rob.R*cos(x(3));  %nouvelle position x du robot
    xdot(2) = ((x(4)+x(5))/2)*rob.R*sin(x(3));  %nouvelle position y du robot
    xdot(3) = (x(4)-x(5))*rob.R/rob.L;          %nouvel angle theta du robot
    xdot(4) = (u(1)-x(4))/tau;              %vitesse angulaire de la roue droite
    xdot(5) = (u(2)-x(5))/tau;              %vitesse angumaire de la roue gauche
    xdot=xdot';                                 %on transpose la matrice pour avoir une matrice colonne 