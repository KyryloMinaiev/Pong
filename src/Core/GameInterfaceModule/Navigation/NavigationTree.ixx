export module NavigationTree;

import NavigationElement;
import UIObject;
import Delegates;
import <vector>;

export class NavigationTree
{
public:
    ~NavigationTree();
    void moveNavigation(NavigationDirection direction);

    void addNavigationElement(UIObject* uiObject);
    void removeNavigationElement(UIObject* uiObject);

    void update();

    Event<NavigationElement*> onNavigationElementChanged;

private:
    void checkElementsPositions();
    void reconstructTree();
    void updateCurrentElement(NavigationElement* element);
    void findNextElement();
    NavigationElement* getClosestElement(const NavigationElement* current, NavigationDirection direction);
    static bool isElementInDirection(const NavigationElement& element,
                                     const NavigationElement& current,
                                     NavigationDirection direction);

    bool m_dirty;
    std::vector<NavigationElement> m_navigationElements;
    NavigationElement* m_current;
};
