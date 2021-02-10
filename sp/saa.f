program multadd
        implicit none
        real*8 r,x,y,z
        real t0,t1,t2,s,m
        integer i,j,ITMAX,IJMAX
        
        
        ITMAX = 10000000
        IJMAX = 50
        r = 3.63        
        x = 0.15 
        z = 0.22
        y = 0
​
        
        call CPU_TIME(t0)
        
        do j=1,IJMAX
        
        
        
            do i=1,ITMAX
                z= r*z*(1-z)
                y = y + z
            end do
        end do        
        
        call CPU_TIME(t1)
        
        x = (x+z)/2
        
        do j=1,IJMAX
            do i=1,ITMAX
                x = r*x*(1-x)
            end do
        end do
​
        
        call CPU_TIME(t2)
        
        
        s = 2*t1 - t2 - t0
        m = (t2-t1 - s)/2
        
        print ,x*y*z,t1-t0,t2-t1,s,m, 2(m+s), 2*m+s
        
        print *,'---------------------'
        
        print *, m/s
    
        
        
        
        end
