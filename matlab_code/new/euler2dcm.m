function DCM = euler2dcm(eu)
    phi=eu(1);
    theta=eu(2);
    gama=eu(3);
    Cphi=[cos(phi) -sin(phi) 0;sin(phi) cos(phi) 0;0 0 1];
    Ctheta=[1 0 0;0 cos(theta) -sin(theta);0 sin(theta) cos(theta)];
    Cgama=[cos(gama) 0 sin(gama);0 1 0;-sin(gama) 0 cos(gama)];
    DCM=Cphi*Ctheta*Cgama;
end

