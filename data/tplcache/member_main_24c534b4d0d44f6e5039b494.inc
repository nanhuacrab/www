<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>��վ��Ա����</title>

<link rel="stylesheet" href="css/reset.css" type="text/css" media="screen" />
<link rel="stylesheet" href="css/style.css" type="text/css" media="screen" />
<link rel="stylesheet" type="text/css" href="css/base.css">
<script language="javascript" src="js/jquery.min.js" type="text/javascript"></script>	
<script type="text/javascript" src="js/admin.jquery.configuration.js"></script>

<script language="javascript" src="js/global.js"></script>
<script language="javascript" src="../include/js/dedeajax2.js"></script>
<script language="javascript" src="js/member.js"></script>
<style type="text/css">
.rb{ border-right:1px solid #666666 }
.tb{ border-top:1px solid #666666 }
</style>
</head>
<body>

<div id="main-content">
<script language="javascript">
$("#member").addClass("current");$("#member_main").addClass("current");</script>				

	<div class="content-box"><!-- Start Content Box -->
				
				<div class="content-box-header">
					
					<h3>��վ��Ա����</h3>
					
					<ul class="content-box-tabs">

					</ul>
					
					<div class="clear"></div>
					
				</div> <!-- End .content-box-header -->
				
				<div class="content-box-content">
					
<div class="tab-content  default-tab" id="tab1">				
<table width="98%" border="0" align="center" cellpadding="3" cellspacing="1" style="margin-bottom:6px">
  <tr>
    <td align="center"> 
  <form action="member_main.php" name="form1" method="get">
	  �ؼ��֣�
          <input name="keyword" type="text" id="keyword" size="12" style="width:120px" value="<?php echo $GLOBALS['keyword']; ?>" />
          &nbsp;����
          
		        <select name="sortkey" id="sortkey" style="width:120px">
              <?php echo $GLOBALS['sortform']; ?>
				      <option value="mid">mid/ע��ʱ��</option>
              <option value="logintime">��¼ʱ��</option>
              <option value="rank">��Ա�ȼ�</option>
              <option value="money">��Ա���</option>
              <option value="scores">��Ա����</option>
            </select>
          
          
		         <select name="sex" id="sex">
               <?php echo $GLOBALS['sexform']; ?>
               <option value="��">��</option>
               <option value="Ů">Ů</option>
               <option value="����">����</option>
             </select>
          
          
          	<select name="mtype" id="mtype" >
               <?php echo $GLOBALS['mtypeform']; 
           		foreach($MemberModels as $row)
           		{
           			echo "<option value=".$row['name'].">".$row['name']."</option>\r\n";
           		}
           	   ?>
             </select>
          
          
		      <select name="spacesta" id="spacesta">
              <option value='-10'>--��Ա״̬--</option>
              <?php
           		foreach($staArr as $k=>$v)
           		{
           			if($spacesta==$k) echo "<option value='$k' selected>$v</option>\r\n";
           			else echo "<option value='$k'>$v</option>\r\n";
           		}
           	  ?>
            </select>
         <input class="button" name="imageField" type="submit" value="����" />
         

	  </form>
    </td>
  </tr>
</table>
<form name="form2">
<table width="98%" border="0" align="center" cellpadding="2" cellspacing="1">
  <tr> 
  <td height="28" colspan="9">
   <table width="99%" border="0" cellspacing="0" cellpadding="0">
     <tr>
       <td width="29%" style="padding-left:10px;"><strong>ע���Ա�б�</strong></td>
       <td width="71%" align="right">
          <a href="member_main.php">���л�Ա</a> |
          <a href="member_main.php?spacesta=-2">�������û�</a> |
          <a href="member_main.php?matt=1">���Ƽ�</a> |
          <a href="member_main.php?matt=0">��ͨ</a> &nbsp;
       </td>
     </tr>
  </table>
 </td>
</tr>
  <tr height="30" align="center"> 
    <td width="3%">ѡ��</td>
    <td width="5%">mid</td>
    <td width="11%">��¼��</td>
    <td width="16%">email/�ǳ�</td>
    <td width="5%">�Ա�</td>
    <td width="8%">��Ա�ȼ�</td>
    <td width="20%">��Ա����</td>
    <td width="14%">����¼</td>
    <td>����</td>
  </tr>
<?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?> 
<tr height="26" align="center"> 
  <td><input name="mid" type="checkbox" id="mid" value="<?php echo $fields['mid']; ?>" class="np" /></td>
  <td><?php echo $fields['mid']; ?></td>
  <td><a href="../member/index.php?uid=<?php echo $fields['userid']; ?>" target='_blank'>
    <?php
	  echo '<u>'.$fields['userid'].'</u>';
	if($fields['spacesta']==-2) echo "<font color='red'>(����)</font>";
	if($fields['spacesta']==-1) echo "<font color='red'>(δ���)</font>";
	  if(!empty($fields['face'])) {
       echo "<br /><img src='{$fields['face']}' width='60' alt='�����Ա�ռ�' />";
	  }
	?>
  </a></td>
	<td>
	  <?php echo $fields['email']; ?>
	  <br />
	  �ǳƣ�<?php echo $fields['uname']; ?>
	</td>
  <td>
  	<?php echo $fields['sex']; ?>
  </td>
  <td>
  	<a href="member_main.php?rank=<?php echo $fields['rank']; ?>"><?php echo GetMemberName($fields['rank'],'���ƻ�Ա'); ?></a>
  </td>
  <td>
  	<?php echo $fields['mtype']; ?>�û� <?php echo GetMAtt($fields['matt']); ?>
  	<br />
  	��ң�<?php echo $fields['money']; ?> ���֣�<?php echo $fields['scores']; ?>
  </td>
  <td>
  	<?php echo MyDate('y-m-d H:i',$fields['logintime']); ?>
  	<br />
  	��<?php echo $fields['loginip']; ?>��
  </td>
  <td align="center">
    <a href="member_view.php?id=<?php echo $fields['mid']; ?>">�޸�</a> | 
    <a href="member_do.php?id=<?php echo $fields['mid']; ?>&dopost=delmember">ɾ��</a> |
    <a href="content_list.php?mid=<?php echo $fields['mid']; ?>" target="_blank">�ĵ�</a> |
    <a href="member_toadmin.php?id=<?php echo $fields['mid']; ?>" target="_self">����</a>
  </td>
</tr>
<?php
}
}?> 
<tr> 
 <td height="36" colspan="9">
	&nbsp;
    <input class="button" name="imageField" type="button" value="ȫѡ" onclick="selAll()" />
    <input class="button" name="imageField" type="button" value="ȡ��" onclick="noSelAll()" />
    <input class="button" name="imageField" type="button" value="ɾ��" onclick="delArc()" />

 ������Ѿ���������̳���û��벻Ҫʹ������ɾ�����ܣ�</td>
</tr>
<tr> 
 <td height="36" colspan="9" align="center">
	<?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '6';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

 </td>
</tr>
</table>
							<div class="clear"></div><!-- End .clear -->
							
						
						
					</div> <!-- End #tab1 -->

					
				</div> <!-- End .content-box-content -->
				
			</div> <!-- End .content-box -->
			
			<div class="clear"></div>
			
           <?php include(DEDEADMIN.'/templets/footer.htm'); ?>
			
		</div> <!-- End #main-content -->	
	</div>
</body>
</html>