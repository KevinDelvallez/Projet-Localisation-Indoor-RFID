clc;
close all;
clf;
clear;
hold on;

Cartographie();
[tg td] = tag();
rob = rob_init();

rayon_tag = 1.5;
dt = 0.1;
Tmax = 100;

x(1) = rob.X; 
x(2) = rob.Y;      
x(3) = rob.theta;  
x(4) = rob.wd;     
x(5) = rob.wg;

global R L dmax wmax Nmin Thetamin % On définit des variables globales pour la fonction contrôle
R = rob.R; % Rayon des roues
L = rob.L; % Demi-entracte entre les roues
dmax = rob.porte; % Portee max d'un laser
wmax = 10; % Vitesse maximale des roues
Nmin = rob.dist_fin_max; % Distance maximale nécessaire avec l'arrivee pour pouvoir s'arrêter
Thetamin = 0.05; % Angle max nécessaire avec l'angle d'arrivee pour pouvoir s'arrêter

%init du tracé du chemin parcouru
X=[];
ptrTraj=plot(x(1),x(2),'b');

for i = 0:1:10
    %nombre_tag = 1 + rand()*3;
    nombre_tag = 1;
    tag_detected = [];
    %while nombre_tag > 0
        t = input('Entrez numéro tag detecté');
        tag_detected = [tag_detected;[tg(t,1) tg(t,2)]];
        nombre_tag = nombre_tag - 1;
        t = 0;
    %end
    arrive = [tag_detected(1) tag_detected(2) 0];
    for t = 0:dt:Tmax
        rob.pc1 = rob.porte; %On remet à zero les distances des capteurs qu'on affiche
        rob.pc2 = rob.porte;
        rob.pc3 = rob.porte;
        dist(1) = rob.porte; %On remet à zero la matrice contenant la distance de detection des capteurs
        dist(2) = rob.porte;
        dist(3) = rob.porte;
        
        rob.X = x(1);
        rob.Y = x(2);
        rob.theta = mod(x(3),2*pi);
        rob.wd = x(4);
        rob.wg = x(5);
        if(rob.theta<0)
            rob.theta = rob.theta + 2*pi;
        end
        
        % Mise à jour du trajet
        X=[X;x]; % On ajoute les coordonnées 
        set(ptrTraj,'xdata',X(:,1),'ydata',X(:,2)); %On met à jour le dessin
        
        % Mise à jour du dessin du robot
        set(rob.ptr,'xdata',[rob.X+(rob.L)*cos(pi/2-rob.theta) rob.X-(rob.L)*cos(pi/2-rob.theta) rob.X+cos(rob.theta)*rob.H],...
        'ydata',[rob.Y-(rob.L)*sin(pi/2-rob.theta) rob.Y+(rob.L)*sin(pi/2-rob.theta) rob.Y+rob.H*sin(rob.theta)]);
        
    % Mise à jour des dessins des capteurs
        set(rob.cap1,'xdata',[rob.X rob.X+rob.pc1*cos(rob.angle+rob.theta)],...
         'ydata',[rob.Y rob.Y+rob.pc1*sin(rob.angle+rob.theta)],'color',rob.couleur(1)); % Capteur 1
        set(rob.cap2,'xdata',[rob.X rob.X+rob.pc2*cos(rob.theta)],...
         'ydata',[rob.Y rob.Y+rob.pc2*sin(rob.theta)],'color',rob.couleur(2)); %Capteur 2
        set(rob.cap3,'xdata',[rob.X rob.X+rob.pc3*cos(-rob.angle+rob.theta)],...
         'ydata',[rob.Y rob.Y+rob.pc3*sin(-rob.angle+rob.theta)],'color',rob.couleur(3)); % Capteur 3

        drawnow; % Cette fonction permet d'actualiser le dessin avec donc les maj effectuées

        %% Commandes
        
        % Mise a jour des arguments de la fonction "controle"
        distance = [rob.pc3 -rob.angle+rob.theta;...
        rob.pc2 rob.theta;...
        rob.pc1 rob.theta+rob.angle]; % Cette matrice comporte 3 lignes pour les 3 capteurs et 2 colonnes pour la distance de detection et l'angle
        Etat = [rob.X rob.Y rob.theta]; % Cette matrice comporte les coordonnées du robot et son angle
        
        % La fonction contrôle renvoie les vitesse wd (u(1)) et wg (u(2))
        u = controle(Etat,arrive,distance);
        
        % Si les vitesse sont nuls (on est arrivé) alors on arrête la
        % simulation
        if(u(1) == 0 && u(2) == 0)
            t = Tmax;
            break;
        end
        
        %% Calcul des nouveaux paramètres
        
        % La fonction ode45 permet de calculer, par rapport aux paramètres
        % actuels, les nouveaux paramètres après le temps dt grâce au systeme d'équation de Laplace dans la fonction Modele 
        [t45,x45] = ode45(@(t,x) Modele(t,x,u,rob),[0 dt],x);
        L45 = length(t45);
        x = x45(L45,:);
    end
end