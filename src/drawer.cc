

#include "drawer.hh"


//////////////////////////////////////////////////////////////////
// Drawer
//////////////////////////////////////////////////////////////////


std::shared_ptr<StringBuffer> 
Drawer::getOutput(const std::shared_ptr<JsonNode>& rootNode)
{
  clear();
  drawNode(rootNode, "", "");
  drawIcon();
  drawFmt();
  return _str_buffer;
}


void
Drawer::drawIcon()
{
  for (int i = 0; i < _str_buffer->size(); ++i) {
    if (_str_buffer->isMarked(i)) // is a leaf node
      _str_buffer->replaceString(i, /*icon's idx*/1, leafIcon);
    else
      _str_buffer->replaceString(i, /*icon's idx*/1, containerIcon);
  }
}

//////////////////////////////////////////////////////////////////
// TreeDrawer
//////////////////////////////////////////////////////////////////


void 
TreeDrawer::drawNode(
  const std::shared_ptr<JsonNode>& jsonNode,
  const std::string& selfCont,
  const std::string& childCont)
{
  if (jsonNode->getLevel()) { // level = 0: root: don't draw
    std::vector<std::string> newLine;
    newLine.push_back(selfCont);                // index 0
    newLine.push_back(" ");                     // index 1
    newLine.push_back(jsonNode->getContent());  // index 2
    
    _str_buffer->addLine(newLine);
    _str_buffer->mark(_str_buffer->size()-1, jsonNode->isLeaf());
  }

  for (const auto& child : jsonNode->getChildren()) {
    if (child == jsonNode->getChildren().back())
      drawNode(child, childCont + branchEnd, childCont + verticalEnd + " ");
    else
      drawNode(child, childCont + branch, childCont + vertical + " ");
  }
}


void
TreeDrawer::drawFmt()
{
  // Draw nothing
}


//////////////////////////////////////////////////////////////////
// RectDrawer
//////////////////////////////////////////////////////////////////


void
RectDrawer::drawNode(
  const std::shared_ptr<JsonNode>& jsonNode,
  const std::string& selfCont,
  const std::string& childCont)
{
  if (jsonNode->getLevel()) { // level = 0: root: don't draw
    std::vector<std::string> newLine;
    newLine.push_back(selfCont);                // index 0
    newLine.push_back(" ");                     // index 1
    newLine.push_back(jsonNode->getContent());  // index 2

    _str_buffer->addLine(newLine);
    int curIdx = _str_buffer->size() - 1;
    _str_buffer->mark(curIdx, jsonNode->isLeaf());
    
    // Trail Part
    const int lineWidth = 44;
    int curWidth = _str_buffer->length(curIdx);
    std::string trail = " ";
    for (int i = 0; i < lineWidth - curWidth; ++i)
      trail += "─";
    _str_buffer->addString(curIdx, trail);      // index 3

    _str_buffer->addString(curIdx, "┤");        // index 4
  }

  for (const auto& child : jsonNode->getChildren()) {
    if (child == jsonNode->getChildren().back())
      drawNode(child, childCont + branchEnd, childCont + verticalEnd + " ");
    else
      drawNode(child, childCont + branch, childCont + vertical + " ");
  }
}


void
RectDrawer::drawFmt()
{
  // replace left-top
  _str_buffer->replaceString(0, 0, "┌─");
  // replace right-top
  _str_buffer->replaceString(0, 4, "┐");
  
  int lastIdx = _str_buffer->size() - 1;
  _str_buffer->replaceString(lastIdx, 0, "│  ", "└──");
  _str_buffer->replaceString(lastIdx, 0, "├", "┴");

  // replace right-bottom
  _str_buffer->replaceString(lastIdx, 4, "┘");
}