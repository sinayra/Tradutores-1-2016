<<<<<<< HEAD
program Exe21;

var 
	a, b: integer;

begin
	read(a,b);
	
	if a <= 10 then
	begin
		write(b);
	end
	else
	begin
		b := b + b;
		write(b);
	end


=======
program Exe22;
(*Imprime valor de c se a, b e c forem menores que 10*)

var 
	a, b, c: integer;

begin
	read(a, b, c);
	
	if a < 10 then
		if b < 10 then
			if c < 10 then
				write(c);
	a := 10;
>>>>>>> 7bf89e855c7a1f1b084376c2f63af16d8940afa6
	write(a);
end.