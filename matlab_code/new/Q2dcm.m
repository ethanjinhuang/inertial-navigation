function  DCM= Q2dcm(Q)
    I=eye(3);
    q0=Q(1);q1=Q(2);q2=Q(3);q3=Q(4);
    qv=[0 -q3 q2;q3 0 -q1;-q2 q1 0];
    DCM=I+2*q0*qv+2*qv*qv;
end

