<?php
	$con=mysqli_connect("localhost","root","","idtest")
	or die ("MySQL 접속 실패");
	$sql="
		INSERT INTO users VALUES
		('LSG',SHA2('LSG', 512),'이승기'),
		('KBS',SHA2('KBS', 512),'김범수'),
		('KKH',SHA2('KKH', 512),'김경호'),
		('JYP',SHA2('JYP', 512),'조용필'),
		('SSK',SHA2('SSK', 512),'성시경')
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