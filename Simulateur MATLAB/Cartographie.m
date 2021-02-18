clc
clear all
close
%% Partie gauche du batiment
bureau_MIRABEL = [0;0];
haut_bureau_MIRABEL = [0;5];
droite_bureau_MIRABEL = [3.83;0];
salle_reu_droit = [3.83;10];
salle_reu_gauche = [0;10];
sortie_couloir_gauche = [0;13];
sortie_couloir_droite = [3.83;13];
coin_sup_gauche = [0;18.33];
coin_sup_gauche_bureau = [3.83;18.33];


%% Partie droite du bat
coin_inf_droit = [25;0];
coin_inf_droite_CAO = [14.17;0];
coin_gauche_porte_bas = [10.34;0];
CAO_haut_droit = [25;8];
CAO_haut_gauche = [14.17;8];
salle_tp_haut_droit = [25;12];
salle_tp_haut_gauche= [16.67;12];
coin_sup_droit = [25;18];


%% Partie centrale du bat

coin_hall_droit = [14.17; 3.33];
coin_hall_gauche = [10.14;3.33];
salle_LT_droite = [14.17;6.66];
salle_LT_gauche = [10.14;6.66];
salle_decoupe_droite = [14.17;13.33];
salle_decoupe_gauche = [10.14;13.33];
porte_centrale_gauche = [10.14;18.33];
porte_centrale_droite = [11.97;18.33];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Dessin du batiment à l'aide de tous les points créés :%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Bureau Mirabel
line([0;3.83],[0;0],'color','blue','linewidth',3)
line([3.83,3.83],[0,5],'color','blue','linewidth',3)
line([0,0], [0,5], 'color','blue','linewidth',3)
line([0,3.83], [5,5,], 'color','blue','linewidth',3)

%% Salle de réu adjacente Mirabel
line([0;3.83],[10;10],'color','blue','linewidth',3)
line([0,0],[0,10],'color','blue','linewidth',3)
line([3.83,3.83], [0,10], 'color','blue','linewidth',3)

%% Couloir
line([0;3.83],[13;13],'color','blue','linewidth',3)

%% Bureau en haut à gauche
line([0;3.83],[18.33;18.33],'color','blue','linewidth',3)
line([0,0],[13,18.33],'color','blue','linewidth',3)
line([3.83,3.83], [13,18.33], 'color','blue','linewidth',3)

%%CAO
line([0;25],[0;0],'color','blue','linewidth',3)
line([14.17,14.17],[0,8],'color','blue','linewidth',3)
line([25,25], [0,18.33], 'color','blue','linewidth',3)
line([14.17,25], [8,8], 'color','blue','linewidth',3)

%% salle de tp
line([0;25],[0;0],'color','blue','linewidth',3)
line([16.67,16.67],[8,12],'color','blue','linewidth',3)
line([25,25], [8,12], 'color','blue','linewidth',3)
line([16.67,25], [12,12],'color','blue','linewidth',3) 
%% hall
line([10.14;14.17],[3.33;3.33],'color','blue','linewidth',3)
line([10.14,10.14],[0,3.33],'color','blue','linewidth',3)

%% LT
line([10.14;14.17],[6.66;6.66],'color','blue','linewidth',3)
line([10.14,10.14],[3.33,6.66],'color','blue','linewidth',3)

%% Salle Découpe
line([14.17;14.17],[8;13.33],'color','blue','linewidth',3)
line([10.14,10.14],[6.66,13.33],'color','blue','linewidth',3)
line([10.14,14.17], [13.33,13.33], 'color','blue','linewidth',3)


%% portes
line([0,10.14], [18.33,18.33],'color','blue','linewidth',3)      
line([11.97,25], [18.33,18.33],'color','blue','linewidth',3)    
line([14.8,15.9],[8,8],'color','red','linewidth',3)             % porte de la cao haut
line([16.67,16.67],[8.5,9.5],'color','red','linewidth',3)       % porte de la salle de TP
line([14.17,14.17],[1.,2.2],'color','red','linewidth',3)        % porte de la cao bas
line([10.14,10.14],[1,2.2],'color','red','linewidth',3)         % porte hall gauche           
line([3.83,3.83],[0.5,1.7],'color','red','linewidth',3)         % Porte François
line([2.7,3.5],[10,10],'color','red','linewidth',3)             % Porte salle de réu
line([2.5,3.3],[13,13],'color','red','linewidth',3)             % Porte bureau Breuil
line([10.14,11.97],[18.33,18.33],'color','red','linewidth',3)   % Porte centrale
line([10.14,10.14],[9.33, 10.13],'color','red','linewidth',3)   % Porte salle de découpe      
line([11.5,13],[3.33,3.33],'color','red','linewidth',3)         % Porte hall haut            
line([23.5,25],[0,0],'color','red','linewidth',3)               % Porte de sortie CAO







