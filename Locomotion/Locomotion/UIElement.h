class CUIElement
{
public:
	~CUIElement() {};

	virtual void Update() = 0;

	virtual void Render() = 0;

	/// <summary>
	/// Enables/disables the button which determines if its Update() and Render() functions should perform.
	/// </summary>
	/// <param name="_bEnabled:">The new enabled state of the button.</param>
	void SetEnabled(bool _bEnabled);

	bool GetEnabled();

protected:
	bool m_bEnabled = true;

	CUIElement() {};
};