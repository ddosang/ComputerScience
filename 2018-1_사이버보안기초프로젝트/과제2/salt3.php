<?php
	$con=mysqli_connect("localhost","root","","salttest")
	or die ("MySQL 접속 실패");
	$sql="
		INSERT INTO users VALUES
		('LSG',SHA2('LSG12!@', 512),'12!@'),
		('KBS',SHA2('KBS34#$', 512),'34#$'),
		('KKH',SHA2('KKH56%^', 512),'56%^'),
		('JYP',SHA2('JYP78&*', 512),'78&*'),
		('SSK',SHA2('SSK90()', 512),'90()')
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