<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>������</title>

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
$("#plus").addClass("current");$("#ad_main").addClass("current");</script>				

	<div class="content-box"><!-- Start Content Box -->
				
				<div class="content-box-header">
					
					<h3>������</h3>
					
					<ul class="content-box-tabs">

					</ul>
					
					<div class="clear"></div>
					
				</div> <!-- End .content-box-header -->
				
				<div class="content-box-content">
					
<div class="tab-content  default-tab" id="tab1">				
<table width="98%" border="0" align="center" cellpadding="3" cellspacing="1" bgcolor="#D6D6D6">
  <tr>
    <td colspan="7" style="padding-left:10px;">
     [<a href="ad_add.php"><u>����һ���¹��</u></a>]
    [<a href="adtype_main.php"><u>���������</u></a>]</td>
</tr>
  <tr>
    <td height="28" colspan="7" style="padding-left:10px;" bgcolor="#FFFFFF"><table>
      <tr>
        <form action='ad_main.php' method='get' name='form3' id="form3">
          <input type='hidden' name='dopost' value='listArchives' />
          <td>��ѡ����ࣺ
              <select name='clsid' style='width:150' id="clsid">
                <option value='0'>Ĭ�Ϸ���...</option>
                
          	<?php echo $option;?>
          
              </select>
              �ؼ��֣�
             <input type='text' name='keyword' style='width:150' />
              
              <input class="button" name="imageField" type="submit" value="����" />
              
           </td>
        </form>
      </tr>
    </table></td>
  </tr>
  <tr align="center"  bgcolor="#FBFCE2"" height="24"> 
      <td width="8%">���</td>
      <td width="20%">����</td>
      <td width="20%">�������</td>
      <td width="12%">Ͷ�ŷ�Χ</td>
      <td width="11%">�Ƿ���ʱ</td>
      <td width="11%">����ʱ��</td>
      <td width="18%">����</td>
   </tr>
   
   <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
    <tr align="center" bgcolor="#FFFFFF" height="24" onMouseMove="javascript:this.bgColor='#FCFDEE';" onMouseOut="javascript:this.bgColor='#FFFFFF';"> 
        <td><?php echo $fields['aid']; ?></td>
        <td><?php echo TestType($fields['clsname'],1); ?></td>
        <td><?php echo $fields['adname']; ?></td>
        <td><?php echo TestType($fields['typename']); ?></td>
        <td><?php echo TimeSetValue($fields['timeset']); ?></td>
        <td><?php echo GetDateMk($fields['endtime']); ?></td>
        <td>
         <a href='ad_edit.php?aid=<?php echo $fields['aid']; ?>&dopost=gettag'>[����]</a>
         <a href='ad_edit.php?aid=<?php echo $fields['aid']; ?>&dopost=edit'>[����]</a>
		     <a href='ad_edit.php?aid=<?php echo $fields['aid']; ?>&dopost=delete'>[ɾ��]</a>
		    </td>
     </tr>
		<?php
}
}?>
     <tr align="center" bgcolor="#F9FCEF" height="24"> 
      <td colspan="7">
      	<?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
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