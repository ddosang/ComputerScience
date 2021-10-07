<?php
	$con=mysqli_connect("localhost","root","","") 
	or die ("MySQL 접속 실패!!");
	$sql = "CREATE DATABASE idtest";
	$ret = mysqli_query($con,$sql);
	
	if($ret){
		echo "idtest가 성공적으로 생성됨";
	}
	else {
		echo "idtest 생성 실패"."<br>";
		echo "실패 원인:".mysqli_error($con);
	}
	mysqli_close($con);

?>