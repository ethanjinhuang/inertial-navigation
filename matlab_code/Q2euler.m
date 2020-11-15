function euler = Q2euler(Q)
    q0=Q(1);q1=Q(2);q2=Q(3);q3=Q(4);
    theta=asin(2*(q2*q3+q0*q1));
    if 2*(q2*q3+q0*q1)<=0.999999
        gama=-atan2(2*(q1*q3-q0*q2),q0^2-q1^2-q2^2+q3^2);
        phi=-atan2(2*(q1*q2-q0*q3),q0^2-q1^2+q2^2-q3^2);
    else
        gama=atan2(2*(q1*q3+q0*q2),q0^2+q1^2-q2^2-q3^2);
        phi=0;
    end
    euler=[phi;theta;gama];
end

