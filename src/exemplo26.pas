program Exe26;
(*
	Lê valores de a e b
	Se a > 10 e b <= 10
		b = a + b
		escreve b
		se b != 16
			escreve (a, a+2, 9)
	senão
		b = 5
		escreve (5, 7, 9)
*)
var 
	a, b: integer;

begin
	read(a,b);
	
	if (a > 10) or (b <= 10) then
	begin
		b := b + a;
		write(b);
		if b <> 16 then
		begin
			write(a, a + 2, 9);
		end
	end
	else
	begin
		b := 5;
		write(b, b + 2, 9);
	end
	

end.