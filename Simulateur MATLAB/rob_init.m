function djo = rob_init()

    djo.rayon_tag = 1.5;

    djo.X = 5;
    djo.Y = 3;
    djo.theta = -pi/6;
    djo.R = 0.05;                %rayon des roues
    djo.L = 0.4;                 %Demi-entracte entre les roues
    djo.H = 0.8;                 %Longueur du djoot
    djo.wd = 0;                  %vitesse angulaire de la roue droite
    djo.wg = 0;                  %vitesse angulaire de la roue gauche
    djo.dist_fin_max = 0.05; 

    %init capteurs
    djo.porte = 3;                     %Porté max du capteur
    djo.pc1 = djo.porte;                 %porté capteur 1
    djo.pc2 = djo.porte;                 %porté capteur 2
    djo.pc3 = djo.porte;                 %porté capteur 3
    djo.angle = pi/6;                    %Angle entre les capteurs
    djo.couleur(1) = 'g';                %Couleurs des capteur initiales
    djo.couleur(2) = 'g';
    djo.couleur(3) = 'g';
    djo.cap1 = line([djo.X djo.X+djo.porte*cos(djo.angle+djo.theta)],[djo.Y djo.Y+djo.porte*sin(djo.angle+djo.theta)],'color',...
    djo.couleur(1),'linewidth',0.5);           %Création ligne capteur 1
    djo.cap2 = line([djo.X djo.X+djo.porte*cos(djo.theta)],[djo.Y djo.Y+djo.porte*sin(djo.theta)],'color',...
    djo.couleur(2),'linewidth',0.5);           %Création ligne capteur 2
    djo.cap3 = line([djo.X djo.X+djo.porte*cos(-djo.angle+djo.theta)],[djo.Y djo.Y+djo.porte*sin(-djo.angle+djo.theta)],'color',...
    djo.couleur(3),'linewidth',0.5);           %Création ligne capteur 3

    %init du dessin du robot
    vertices_djo = [djo.X+(djo.L)*cos(pi/2-djo.theta),djo.Y-(djo.L)*sin(pi/2-djo.theta);...
              djo.X-(djo.L)*cos(pi/2-djo.theta),djo.Y+(djo.L)*sin(pi/2-djo.theta);...
              djo.X+cos(djo.theta)*djo.H,djo.Y+djo.H*sin(djo.theta)];
    face_djo = [1 2 3];
    djo.ptr = patch('vertices',vertices_djo,'faces',face_djo);
    
    rob.rayon_tag = 1.5;
end