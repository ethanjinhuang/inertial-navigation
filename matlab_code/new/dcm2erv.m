function erv = dcm2erv(dcm)
    Q=dcm2Q(dcm);
    erv=Q2erv(Q);
end

