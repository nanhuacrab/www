<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>�Զ�����</title>

<link rel="stylesheet" href="css/reset.css" type="text/css" media="screen" />
<link rel="stylesheet" href="css/style.css" type="text/css" media="screen" />
<link rel="stylesheet" type="text/css" href="css/base.css">
<script language="javascript" src="js/jquery.min.js" type="text/javascript"></script>	
<script type="text/javascript" src="js/admin.jquery.configuration.js"></script>

<script language="javascript" src="js/global.js"></script>
<script language="javascript" src="../include/js/dedeajax2.js"></script>

</head>
<body>

<div id="main-content">
<script language="javascript">
$("#templets").addClass("current");$("#mytag_main").addClass("current");</script>				

	<div class="content-box"><!-- Start Content Box -->
				
				<div class="content-box-header">
					
					<h3>�Զ�����</h3>
					
					<ul class="content-box-tabs">

					</ul>
					
					<div class="clear"></div>
					
				</div> <!-- End .content-box-header -->
				
				<div class="content-box-content">
					
<div class="tab-content  default-tab" id="tab1">				
<table width="98%" border="0" align="center" cellpadding="3" cellspacing="1">
  <tr>
   <td colspan="7"  style="padding-left:10px;">
    
     &nbsp;[<a href="mytag_add.php"><u>����һ�����</u></a>]
     &nbsp;[<a href="mytag_tag_guide.php"><u>���ܱ����</u></a>]
	</td>
</tr>
  <tr align="center"> 
      <td width="10%">���</td>
      <td width="20%">�������</td>
      <td width="15%">������Ŀ</td>
      <td width="15%">ʱ������</td>
      <td width="20%">����ʱ��</td>
      <td width="20%">����</td>
   </tr>
   <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
    <tr align="center"> 
        <td><?php echo $fields['aid']; ?></td>
        <td><?php echo $fields['tagname']; ?></td>
        <td><?php echo TestType($fields['typename']); ?></td>
        <td><?php echo TimeSetValue($fields['timeset']); ?></td>
        <td><?php echo GetDateMk($fields['endtime']); ?></td>
        <td>
          	<a href='mytag_edit.php?aid=<?php echo $fields['aid']; ?>&dopost=edit'>����</a> | 
		        <a href='mytag_edit.php?aid=<?php echo $fields['aid']; ?>&dopost=delete'>ɾ��</a> | 
		        <a href='mytag_edit.php?aid=<?php echo $fields['aid']; ?>&dopost=getjs'>JS����</a>
		    </td>
     </tr>
		<?php
}
}?>
     <tr align="center"> 
      <td colspan="7">
      	<?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '6';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

      </td>
     </tr>
   </table>
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