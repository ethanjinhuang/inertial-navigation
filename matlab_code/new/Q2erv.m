function erv = Q2erv(Q)
    if Q(1)<0
        Q=-Q;
    end
    nmhalf=acos(Q(1));
    if nmhalf>1e-20
        b=2*nmhalf/sin(nmhalf);
    else
        b=2;
    end   
    erv=b*Q(2:4);
end

