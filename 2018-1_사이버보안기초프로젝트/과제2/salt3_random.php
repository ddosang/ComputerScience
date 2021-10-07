<?php
	$con=mysqli_connect("localhost","root","","salttest1")
	or die ("MySQL 접속 실패");
	
	$rn1 = mt_rand(1, 100);
	$rn2 = mt_rand(1, 100);
	$rn3 = mt_rand(1, 100);
	$rn4 = mt_rand(1, 100);
	$rn5 = mt_rand(1, 100);
	$sql="
		INSERT INTO users VALUES
		('LSG',SHA2('LSG$rn1', 512),$rn1),
		('KBS',SHA2('KBS$rn2', 512),$rn2),
		('KKH',SHA2('KKH$rn3', 512),$rn3),
		('JYP',SHA2('JYP$rn4', 512),$rn4),
		('SSK',SHA2('SSK$rn5', 512),$rn5)
	";//sql문 안에서 sha를 돌리는거니가 sql 문법으로 해야함.
	$ret =mysqli_query($con, $sql);
	if ($ret)
	echo ("데이터가 성공적으로 입력됨");
	else{
		echo "데이터 입력 실패!!"."<br>";
		echo "실패 원인:".mysqli_error($con);
	}
	mysqli_close($con);

?>