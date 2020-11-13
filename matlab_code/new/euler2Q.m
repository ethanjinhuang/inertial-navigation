function Q= euler2Q(eu)
%EULER2Q 此处显示有关此函数的摘要
%   此处显示详细说明
    s=sin(eu/2);
    c=cos(eu/2);
    Q=[c(1)*c(2)*c(3)-s(1)*s(2)*s(3);
        c(1)*s(2)*c(3)-s(1)*c(2)*s(3);
        s(1)*s(2)*c(3)+c(1)*c(2)*s(3);
        s(1)*c(2)*c(3)+c(1)*s(2)*s(3)]
end

