function [tag_coord tag_dessin]= tag()
    ep = 2;
    
    % salle de projet
    c = 'og';
    tag_coord(5,1) = 3.83; tag_coord(5,2) = 2;
    tag_dessin(5) = plot(tag_coord(5,1),tag_coord(5,2),c,'linewidth',ep);
    tag_coord(6,1) = 3.83 ; tag_coord(6,2) = 4;
    tag_dessin(6) = plot(tag_coord(6,1),tag_coord(6,2),c,'linewidth',ep);
    tag_coord(15,1) = 3.83; tag_coord(15,2) = 17;
    tag_dessin(15) = plot(tag_coord(15,1),tag_coord(15,2),c,'linewidth',ep);
    tag_coord(16,1) = 3.83; tag_coord(16,2) = 15;
    tag_dessin(16) = plot(tag_coord(16,1),tag_coord(16,2),c,'linewidth',ep);
    tag_coord(9,1) = 2; tag_coord(9,2) = 10;
    tag_dessin(9) = plot(tag_coord(9,1),tag_coord(9,2),c,'linewidth',ep);
    tag_coord(11,1) = 2; tag_coord(11,2) = 13;
    tag_dessin(11) = plot(tag_coord(11,1),tag_coord(11,2),c,'linewidth',ep);
    tag_coord(10,1) = 3.83; tag_coord(10,2) = 8;
    tag_dessin(10) = plot(tag_coord(10,1),tag_coord(10,2),c,'linewidth',ep);
    tag_coord(17,1) = 6; tag_coord(17,2) = 18.33;
    tag_dessin(17) = plot(tag_coord(17,1),tag_coord(17,2),c,'linewidth',ep);
    tag_coord(18,1) = 9; tag_coord(18,2) = 18.33;
    tag_dessin(18) = plot(tag_coord(18,1),tag_coord(18,2),c,'linewidth',ep);
    tag_coord(19,1) = 13; tag_coord(19,2) = 18.33;
    tag_dessin(19) = plot(tag_coord(19,1),tag_coord(19,2),c,'linewidth',ep);
    tag_coord(20,1) = 16; tag_coord(20,2) = 18.33;
    tag_dessin(20) = plot(tag_coord(20,1),tag_coord(20,2),c,'linewidth',ep);
    tag_coord(21,1) = 19; tag_coord(21,2) = 18.33;
    tag_dessin(21) = plot(tag_coord(21,1),tag_coord(21,2),c,'linewidth',ep);
    tag_coord(22,1) = 23; tag_coord(22,2) = 18.33;
    tag_dessin(22) = plot(tag_coord(22,1),tag_coord(22,2),c,'linewidth',ep);
    tag_coord(23,1) = 25; tag_coord(23,2) = 16;
    tag_dessin(23) = plot(tag_coord(23,1),tag_coord(23,2),c,'linewidth',ep);
    tag_coord(24,1) = 25; tag_coord(24,2) = 13;
    tag_dessin(24) = plot(tag_coord(24,1),tag_coord(24,2),c,'linewidth',ep);
    tag_coord(25,1) = 7; tag_coord(25,2) = 0;
    tag_dessin(25) = plot(tag_coord(25,1),tag_coord(25,2),c,'linewidth',ep);
    tag_coord(26,1) = 22; tag_coord(26,2) = 12;
    tag_dessin(26) = plot(tag_coord(26,1),tag_coord(26,2),c,'linewidth',ep);
    tag_coord(27,1) = 17;tag_coord(27,2) = 12;
    tag_dessin(27) = plot(tag_coord(27,1),tag_coord(27,2),c,'linewidth',ep);
    tag_coord(28,1) = 13; tag_coord(28,2) = 13.33;
    tag_dessin(28) = plot(tag_coord(28,1),tag_coord(28,2),c,'linewidth',ep);
    tag_coord(29,1) = 10.14; tag_coord(29,2) = 12;
    tag_dessin(29) = plot(tag_coord(29,1),tag_coord(29,2),c,'linewidth',ep);
    tag_coord(30,1) = 10.14; tag_coord(30,2) = 8;
    tag_dessin(30) = plot(tag_coord(30,1),tag_coord(30,2),c,'linewidth',ep);
    tag_coord(31,1) = 10.14; tag_coord(31,2) = 6;
    tag_dessin(31) = plot(tag_coord(31,1),tag_coord(31,2),c,'linewidth',ep);
    tag_coord(32,1) = 10.14; tag_coord(32,2) = 4;
    tag_dessin(32) = plot(tag_coord(32,1),tag_coord(32,2),c,'linewidth',ep);
    tag_coord(33,1) = 10.14; tag_coord(33,2) = 0.4;
    tag_dessin(33) = plot(tag_coord(33,1),tag_coord(33,2),c,'linewidth',ep);
    
    
    % Bureau mirabel
    c = 'or';
    tag_coord(1,1) = 0; tag_coord(1,2) = 0;
    tag_dessin(1) = plot(tag_coord(1,1),tag_coord(1,2),c,'linewidth',ep);
    tag_coord(2,1) = 0; tag_coord(2,2) = 2;
    tag_dessin(2) = plot(tag_coord(2,1),tag_coord(2,2),c,'linewidth',ep);
    tag_coord(3,1) = 0; tag_coord(3,2) = 4;
    tag_dessin(3) = plot(tag_coord(3,1),tag_coord(3,2),c,'linewidth',ep);
    tag_coord(4,1) = 2; tag_coord(4,2) = 0;
    tag_dessin(4) = plot(tag_coord(4,1),tag_coord(4,2),c,'linewidth',ep);
    
    
    % Salle de reunion
    c = 'oblack';
    tag_coord(7,1) = 2; tag_coord(7,2) = 5;
    tag_dessin(7) = plot(tag_coord(7,1),tag_coord(7,2),c,'linewidth',ep);
    tag_coord(8,1) = 0; tag_coord(8,2) = 8;
    tag_dessin(8) = plot(tag_coord(8,1),tag_coord(8,2),c,'linewidth',ep);
    
    
    % Bureau breuil
    c = 'oy';
    tag_coord(12,1) = 0; tag_coord(12,2) = 15;
    tag_dessin(12) = plot(tag_coord(12,1),tag_coord(12,2),c,'linewidth',ep);
    tag_coord(13,1) = 0; tag_coord(13,2) = 17;
    tag_dessin(13) = plot(tag_coord(13,1),tag_coord(13,2),c,'linewidth',ep);
    tag_coord(14,1) = 2; tag_coord(14,2) = 18.33;
    tag_dessin(14) = plot(tag_coord(14,1),tag_coord(14,2),c,'linewidth',ep);
    

end