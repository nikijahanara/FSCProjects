package Jahanara.bcs345.purchases.presentation;

import javafx.application.Application;
/**
 * The PurchasesGraphicalUI class contains the definition for its only method, ShowUI. ShowUI
 * launches the Purchases window created in the PurchasesApplication class when it is called.
 * 
 * @author Niki Jahanara
 * @version 1.0
 * @since 12/8/16
 */
public class PurchasesGraphicalUI {

	/**
	 *  The ShowUI method of the PurchasesGraphicalUI class launches the PurchasesApplication class,
	 *  which means that a call to PurchasesGraphicalUI's ShowUI method will display the window
	 *  that was created in PurchaseApplication to the user.
	 */
	public void ShowUI() {
		
		//****************************************************************
		// Launching the PurchasesApplication class so that a window
		// is displayed when the ShowUI method is called.
		//****************************************************************
		Application.launch(PurchasesApplication.class);
	}
}
