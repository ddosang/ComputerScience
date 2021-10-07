<?php
	$con = mysqli_connect("localhost","root","","salttest1") 
	or die("MySQL 접속 실패!!");
	$sql ="
		CREATE TABLE users
			(ID VARCHAR(20) NOT NULL PRIMARY KEY,
			PWD TEXT(512) NOT NULL,
			SALT VARCHAR(20))
	
	";
	$ret =mysqli_query($con,$sql);
	if ($ret){
		echo "users가 성공적으로 생성됨";
	}
	else {
		echo "users 생성 실패!!"."<br>";
		echo "실패 원인:".mysqli_error($con);
		
	}
	mysqli_close($con);

?>