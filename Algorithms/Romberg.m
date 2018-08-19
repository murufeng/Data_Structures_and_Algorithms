function [quad,R]=Romberg(a,b,eps)
      h=b-a;
      R(1,1)=(h/2)*(f(a)+f(b));
      n=1;
      j=0;
      err=1;
      while err>eps
          j=j+1;
          h=h/2;
          s=0;
        for i=1:n
            x=a+h*(2*i-1);
            s=s+f(x);
        end
        R(j+1,1)=R(j,1)/2+h*s;
        n=2*n;
        for k=1:j
            R(j+1,k+1)=R(j+1,k)+(R(j+1,k)-R(j,k))/(4^k-1);
        end
        err=abs(R(j+1,j)-R(j+1,j+1));
      end
      quad=R(j+1,j+1);
end
